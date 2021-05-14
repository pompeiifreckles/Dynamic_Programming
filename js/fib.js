// fib(n) returns nth number of fibonacci series
// n = 1 -> 1
// n = 0 -> 0


function fib(n) {
	const table = Array.from({length: n+1}, () => 0)
	table[1] = 1

	for (let i=0; i <= n; i++) {
		table[i+1] += table[i]
		table[i+2] += table[i]
	}
	return table[n]
}

console.log(fib(6))
