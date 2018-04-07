T = input()

#print "Number of test cases: {}".format(T)

def swap(s,i,j):
	s = list(s)
	s[i], s[j] = s[j], s[i]
	return ''.join(s)

def countdmg(seq):
	last = len(seq)
	mul = 2
	currentdmg = 1
	totaldmg = 0
	for action in seq:
		if action == 'S':
			totaldmg += currentdmg
		elif action == 'C':
			currentdmg *= mul
	return totaldmg
	
def is_possible(seq):
		if "CS" not in seq:
			return False
		else:
			return True
			
def swap_last_cs(seq):
	last = len(seq) - 1
	current = last
	while current != 0:
		if seq[current] == "S" and seq[current - 1] == "C":
			seq = swap(seq, current, current - 1)
			break
		else:
			current -= 1
	return seq

testnum = 0

while testnum < T:
	testcase = raw_input()
	temp = testcase.strip().split(" ")
	dmgcap = int(temp[0])
	seq = temp[1]
	
	#print "Shield damage block capacity is {} \nAnd the action sequence of gun is {}".format(dmgcap,seq)
	
	swaps = 0
	impossible = False
	success = False
	
	if countdmg(seq) > dmgcap and not is_possible(seq):
			#print "Total damage {} is greater than damage block cap {}, and no swap is possible in sequence! \nMISSION IMPOSSIBLE!!!".format(countdmg(), dmgcap)
			impossible = True
	
	while not impossible and not success:
		#print "Current sequence: {}".format(seq)
		#print "Total damage: {}\n Damage block: {}".format(countdmg(seq), dmgcap)
		if countdmg(seq) <= dmgcap:
			#print "SUCCESS!!!"
			success = True
			break
		else:
			if not is_possible(seq):
				impossible = True
				break
			#print "Try swap!"
			seq = swap_last_cs(seq)
			swaps += 1
			#print "New sequence: {}".format(seq)
			
	print "Case #{}: {}".format(testnum+1, swaps if not impossible else "IMPOSSIBLE")
	
	testnum += 1