#!/usr/bin/env python

words = [
	'',
	'one',
	'two',
	'three',
	'four',
	'five',
	'six',
	'seven',
	'eight',
	'nine',
	'ten',
	'eleven',
	'twelve',
	'thirteen',
	'fourteen',
	'fifteen',
	'sixteen',
	'seventeen',
	'eighteen',
	'nineteen'
]
for t in ['twenty', 'thirty', 'forty', 'fifty', 'sixty', 'seventy', 'eighty', 'ninety']:
	words.append(t)
	for i in range(1, 10):
		words.append(t + words[i])
for h_ in range(1, 10):
	h = words[h_] + 'hundred'
	words.append(h)
	for i in range(1,100):
		words.append(h + 'and' + words[i])
words.append('onethousand')

print(len(''.join(words)))
