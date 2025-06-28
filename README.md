# Test Your Code

VSCode extension to test your algorithm implementations.  
Provide the following in a folder:

- `good.cpp`: the correct implementation
- `test.cpp`: your test solution
- `input_generator.ts`: generates randomized test input

This extension will:
1. Compile all three files.
2. Generate input via `input_generator.cpp`.
3. Run both `good.cpp` and `test.cpp` on the same input.
4. Compare outputs and report mismatches as counterexamples.

## Usage

- Open a folder with all three C++ files
- Run the command:
  > `Test Your Code: Generate Counterexample`
- If a mismatch is found, the input will be shown in the output console.

## Requirements

- You must have `g++` available in your system PATH

## Release Note

- v1.1.1 Change  `input_generator.cpp` to `input_generator.ts`