// memoized fibonacci

const fib = n => {
	const obj = {}
	return (function fib(n) {

			if (n <= 2) return 1
			if (obj[n] !== undefined) return obj[n]

			obj[n] = fib(n-1) + fib(n-2)
			return obj[n]
	})(n)
}

console.log(fib(8))
console.log(fib(50))
