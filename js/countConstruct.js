// countConstruct(abcdef, [ab, cd, abc, def, abcd]) -> 1
// countConstruct(purple, [purp, p, ur, l, purpl]) -> 2



function canConstruct(target, wordBank, memo = {}) {
	if (target in memo) return memo[target]
	if (target == '') return 1
	
	let totalCount = 0

	for (let word of wordBank) {
		const size = word.length
		if (target.slice(0, size) === word) {
			const numWays = canConstruct(target.slice(size), wordBank, memo)
			totalCount += numWays
		}
	}

	memo[target] = totalCount
	return totalCount
}

console.log(canConstruct('abcdef', ['abc', 'a', 'bc', 'def', 'd']))
console.log(canConstruct('eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef', [
	'e',
	'ee',
	'eee',
	'eeee',
	'eeeee',
]))
