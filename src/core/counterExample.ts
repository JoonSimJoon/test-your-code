import { prepareAndRunAll, compileCpp, runCpp } from "./cppExecutor";
import * as path from "path";

function getInputFromCppGenerator(testDir: string): string {
    const genSrc = path.join(testDir, "input_generator.cpp");
    const genBin = path.join(testDir, "input_generator_exec");

    compileCpp(genSrc, genBin);
    return runCpp(genBin, "");
}

export function findCounterExample(testDir: string, tries: number = 100): string | null {
    for (let i = 0; i < tries; i++) {
        const input = getInputFromCppGenerator(testDir);

        try {
            const { goodOutput, testOutput } = prepareAndRunAll(testDir, input);
            if (goodOutput !== testOutput) {
                console.log("❗ Counterexample found!");
                console.log("Input:\n" + input);
                console.log("Expected Output:\n" + goodOutput);
                console.log("Your Output:\n" + testOutput);
                return input;
            }
        } catch (err) {
            console.error("Error during test run:", err);
        }
    }

    console.log("✅ No counterexample found.");
    return null;
}