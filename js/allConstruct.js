// allConstruct(target, wordBank) return 2D array 
// containing all possible combinations
//
// allConstruct(purple, [purp, p, le, ur, purpl])
// [
// 		[purp, le],
// 		[p, ur, p, le]
// ]


function allConstruct(target, wordBank, memo = {}) {
	if (target in memo) return memo[target]
	if (target === '') return [[]]

	const result = []

	for (let word of wordBank) {
		const size = word.length
		if (target.slice(0, size) === word) {
			const suffixWays = allConstruct(target.slice(size), wordBank, memo)
			const targetWays = suffixWays.map(way => [word, ...way])
			result.push(...targetWays)
		}
	}

	memo[target] = result
	return result
}


console.log(allConstruct('skateboard', ['purp', 'p', 'le', 'ur', 'purpl']))
console.log(allConstruct('purple', ['purp', 'p', 'le', 'ur', 'purpl']))
console.log(allConstruct('abc', ['a', 'bc', 'ab', 'c']))
