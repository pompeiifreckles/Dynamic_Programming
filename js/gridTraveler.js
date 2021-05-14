// Travel a M x N grid by using dynamic programming
// only possible movements -> down, right
// start -> top-left, end -> bottom-right

function gridTraveler(m, n, memo={}) {
	const key = m + ',' + n

	if (memo[key] !== undefined) return memo[key]
	if (m === 1 && n === 1) return 1
	if (m === 0 || n === 0) return 0

	memo[key] = gridTraveler(m-1, n, memo) + gridTraveler(m, n-1, memo)
	return memo[key]
}


console.log(gridTraveler(3, 3))
console.log(gridTraveler(6, 6))
console.log(gridTraveler(18, 18))
