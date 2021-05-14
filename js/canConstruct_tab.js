// canConstruct(target, wordBank)
//
// canConstruct(abcdef, [ab, abc, cd, def, abcd]) -> true

function canConstruct(target, wordBank) {
	const table = Array(target.length + 1).fill(false)
	table[0] = true

	for (let i=0; i <= target.length; i++) {
		if (table[i])
			for (let word of wordBank) {
				const size = word.length
				if (target.slice(i, size+i) === word) {
					table[size + i] = true
				}
			}
	}

	// console.log(table)
	return table[target.length]
}



console.log(canConstruct('abcdef', ['ab', 'abc', 'cd', 'def', 'abcd']))
console.log(canConstruct('skateboard', ['ab', 'skate', 'd', 'boar']))
console.log(canConstruct('eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef', [
	'e',
	'ee',
	'eee',
	'eeee',
	'eeeee',
	'eeeeee'
]))
