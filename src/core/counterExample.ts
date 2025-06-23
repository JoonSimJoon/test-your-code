import { prepareAndRunAll, compileCpp, runCpp } from "./cppExecutor";
import * as path from "path";

async function getInputFromTsModule(testDir: string): Promise<string> {
    const generatorModule = await import(path.resolve(testDir, "input_generator.ts"));
    return generatorModule.generateInput();
}

async function findCounterExample(testDir: string, tries: number = 40): Promise<string | null> {
    for (let i = 0; i < tries; i++) {
        const input = await getInputFromTsModule(testDir);  // 여기!
        const { goodOutput, testOutput } = prepareAndRunAll(testDir, input);
        try {
            if (goodOutput !== testOutput) {
                console.log("❗ Counterexample found!");
                console.log("Input:\n" + input);
                console.log("Expected Output:\n" + goodOutput);
                console.log("Your Output:\n" + testOutput);
                return input;
            }else{
                console.log(i+1+" test suceed");
                console.log("Input:\n" + input);
                console.log("Expected Output:\n" + goodOutput);
                console.log("Your Output:\n" + testOutput);

            }
        } catch (err) {
            console.error("Error during test run:", err);
        }
    }

    console.log("✅ No counterexample found.");
    return null;
}
export { findCounterExample };