import { execSync } from "child_process";
import * as fs from "fs";
import * as path from "path";

const TIMEOUT_MS = 2000;

export function compileCpp(sourcePath: string, outputPath: string): void {
    const compileCmd = `g++ "${sourcePath}" -o "${outputPath}" -std=c++17 -O2`;
    try {
        execSync(compileCmd, { stdio: "inherit" });
    } catch (err) {
        throw new Error(`Compilation failed for ${sourcePath}`);
    }
}

export function runCpp(binaryPath: string, input: string): string {
    try {
        const output = execSync(`echo "${input}" | "${binaryPath}"`, {
            timeout: TIMEOUT_MS,
            encoding: "utf-8",
        });
        return output.trim();
    } catch (err) {
        throw new Error(`Execution failed for ${binaryPath}`);
    }
}

export function prepareAndRunAll(testDir: string, input: string): {
    goodOutput: string;
    testOutput: string;
} {
    const goodSrc = path.join(testDir, "good.cpp");
    const testSrc = path.join(testDir, "test.cpp");
    const goodBin = path.join(testDir, "good_exec");
    const testBin = path.join(testDir, "test_exec");

    compileCpp(goodSrc, goodBin);
    compileCpp(testSrc, testBin);

    const goodOutput = runCpp(goodBin, input);
    const testOutput = runCpp(testBin, input);

    return { goodOutput, testOutput };
}