// allConstruct(target, wordBank)
//
// allConstruct(abcdef, [ab, abc, cd, def, abcd, ef, c])

function allConstruct(target, wordBank) {
	const table = Array(target.length + 1).fill().map(() => [])
	table[0] = [[]]

	for (let i=0; i<=target.length; i++) {
		if (target[i] !== null)
			for (let word of wordBank) {
				const size = word.length
				if (target.slice(i, i + size) === word) {
					const combinations = table[i].map(subArray => [...subArray, word])
					table[size + i].push(...combinations)
				}
			}
	}

	return table[target.length]
}


console.log(allConstruct('abcdef', ['ab', 'abc', 'cd', 'def', 'abcd', 'ef', 'c']))
console.log(allConstruct('abcdefg', ['ab', 'abc', 'cd', 'def', 'abcd', 'ef', 'c']))
