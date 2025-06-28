export function generateInput(): string {
    const N = Math.floor(Math.random() * 30) + 1;
    const arr = Array.from({ length: N }, () =>
        Math.floor(Math.random() * 100) + 1
    );
    return `${N}\n${arr.join(" ")}`;
}