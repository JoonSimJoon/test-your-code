export function generateInput(): string {
    const N = Math.floor(Math.random() * 10) + 1;
    const arr = Array.from({ length: N }, () =>
        Math.floor(Math.random() * 1000) + 1
    );
    return `${N}\n${arr.join(" ")}`;
}