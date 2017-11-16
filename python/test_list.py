# [ <expression> for <element> in <iterable> ]
# [ <expression> for <element> in <iterable> if <condition> ]

test = []
for x in (1,2,3,4):
    test.append(x);

print (test)

test2 = [s.upper() for s in "Hello World"]
print (test2)

test3 = [w.strip(',') for w in ['these,', 'words,,', 'mostly', 'have,commas,']]
print (test3)

sentence = "Beautiful is better than ugly"
test4 = ["".join(sorted(word, key=lambda x: x.lower())) for word in sentence.split()]
print (test4)

sentence2 = 'apple'
# error
# [x for x in 'apple': if x in 'aeiou' else '*']
print (sentence2)

test5 = [x if x in 'aeiou' else '*' for x in 'apple']
print (test5)

invalidstr = [' ', '\t', '\n']
test6 = [x if x not in invalidstr else '#' for x in 'tgeahketheak  hefeakhe   haewkhgf']
print (test6)

test7= [x*10 for x in range(10) if x%2 ==0]
print (test7)

# <value-if-condition-is-true> if <condition> else <value-if-condition-is-false>
test8 = [x if (x/2==0) else -1 for x in range(10)]
print (test8)
