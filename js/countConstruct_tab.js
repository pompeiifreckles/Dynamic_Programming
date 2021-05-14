// countConstruct(target, wordBank)
//
// countConstruct(purple, [purp, p, ur, le, purpl]) -> 2


function countConstruct(target, wordBank) {
	let table = Array(target.length + 1).fill(0)
	table[0] = 1

	for (let i=0; i<=target.length; i++) {
		if (target[i] !== 0)
			for (let word of wordBank) {
				const size = word.length
				if (target.slice(i, size + i) === word) {
					table[size + i] += table[i]
				}
			}
	}

	// console.log(table)
	return table[target.length]
}


console.log(countConstruct('purple', ['purp', 'p', 'ur', 'le', 'purpl']))
