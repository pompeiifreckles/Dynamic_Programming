const A = [
  [ 1, 2, 3, -1, -2 ],
  [ -5, -8, -1, 2, -150 ],
  [ 1, 2, 3, -250, 100 ],
  [ 1, 1, 1, 1, 20 ]
]


function max(a, b) {
	return (a > b) ? a : b
}

const ms = n => (x, y) => {
	return max(msl(x,y + n) + A[x][y], 0)
}

const msl = ms(-1)
const msr = ms(1)

const msit = n => (x, y) => {
	return max(mslit(x, y-1) + A[x][y], dp)
}

function matrixLand(A, memo = {}) {
	const m = A[0].length
	const n = A.length


}

console.log(matrixLand(A))
