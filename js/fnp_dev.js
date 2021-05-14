// Find G(n) if G(n) = 2*G(n) - 3*G(n-1) + G(n-3)
// G(1) = 5, G(2) = 3, G(3) = 3
// 0 < n < 80

function funcSolver(n) {
	if (n <= 0 || n >= 80) return null
	return (function solve(n, memo = {}) {
		if (n in memo) return memo[n]
		if (n === 1) return 5
		if (n === 3 || n == 2) return 3
		
		memo[n] = 3*solve(n-1, memo) - solve(n-3, memo)
		return memo[n]
	})(n)
}

console.log(funcSolver(1))
console.log(funcSolver(2))
console.log(funcSolver(3))
console.log(funcSolver(4))
console.log(funcSolver(79))
console.log(funcSolver(90))
console.log(funcSolver(0))
