import re
from fractions import Fraction

class LinearSystem:

	def __init__(self, equations):
		self.matrix = equations

	def type1Row(self, i, j):
		print(f"After Type 1 operation: row({i+1}) <-> row({j+1})\n")
		self.matrix[i], self.matrix[j] = self.matrix[j], self.matrix[i]
		self.printMatrix()

	def type2Row(self, c, i):
		print(f"After Type 2 operation: {str(Fraction(c).limit_denominator())}*row({i+1}) -> row({i+1})\n")
		self.matrix[i] = [element * c for element in self.matrix[i]]
		self.printMatrix()
	
	def type3Row(self, m, j, i):
		print(f"After Type 3 operation: {str(Fraction(m).limit_denominator())}*row({j+1})+row({i+1}) -> row({i+1})\n")
		self.matrix[i] = [m * self.matrix[j][x] + self.matrix[i][x] for x in range(len(self.matrix[i]))]
		self.printMatrix()

	def ref(self):
		# place all equations with more zeroes from the right at the bottom of the matrix
		new_matrix = [0] * len(self.matrix)
		non_zero_idx = []

		for i in range(len(self.matrix)):
			for j in range(len(self.matrix[i])):
				if self.matrix[i][j] != 0:
					non_zero_idx.append((i, j))
					break

		non_zero_idx.sort(key=lambda i:i[1])

		for i in range(len(non_zero_idx)):
			new_matrix[i] = self.matrix[non_zero_idx[i][0]]

		self.matrix = new_matrix

		print("Re-ordering matrix using Type1 operations:\n")
		self.printMatrix()

		# make the left most non-zero element of the row be the leading 1
		print("Converting to ref:\n")
		for c in range(len(self.matrix)):
			non_zero = 0
			for i in range(len(self.matrix[c])):
				if self.matrix[c][i] != 0:
					non_zero = i
					break

			if self.matrix[c][non_zero] != 1:
				self.type2Row(1/self.matrix[c][non_zero], c)

			for r in range(non_zero + 1, len(self.matrix)):
				if self.matrix[r][c] != 0:
					self.type3Row(-self.matrix[r][c], c, r)

		print("REF of System:\n")
		self.printMatrix()
	
	def rref(self):
		
		print("Finding the RREF:\n")
		for r in range(len(self.matrix) - 1, 0, -1):
			lead_idx = 0

			# find the index of the leading 1
			for i in range(len(self.matrix[r])):
				if self.matrix[r][i] == 1:
					lead_idx = i

			for r2 in range(r):
				if self.matrix[r2][lead_idx] != 0:
					self.type3Row(-self.matrix[r2][lead_idx], r, r2)
			
		print("RREF of System:\n")
		self.printMatrix()


	def printMatrix(self):
		for equation in self.matrix:
			print('[%s]' % ' '.join(map(str, [str(Fraction(coefficient).limit_denominator()) for coefficient in equation])))
		print()
	
x = [
	[-2, 1, 6, -3, -7],
	[1, 1, 2, 5, 91],
	[0, 9, 3, -7, -2],
	[2, -3, 4, 11, 151]
]


l = LinearSystem(x)

l.printMatrix() 
l.ref()
l.rref()



			


