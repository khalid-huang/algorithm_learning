# -*- coding: utf-8 -*- 
#according the pre_traversal and the in_traversal to get the post_traversal
#算法的思想：首先我们可以看到在先序遍历中的第一个字符就是根结点，而根据这个根结点在中序遍历中的位置我们就可以确定这个根结点的左右子树了。利用这样的思想，就可以进行递归。比如我们有先序DBACEGF，中序ABCDEFG，根据先序的第一个字符确定根结点为D,其在中序的位置为3，所以可以得到其左右子树为ABC,EFG,对应的其先序也可以从一开始的先序中得到为BAC和EGF，而对于D，因为我们要生成后序，我们只要把它加到字符串的最后就可以了。这样又可以进行递归了、直到长度为0.
#画一个递归树

#这个函数的用意是使用两个size为size的pre_s和in_s生成一个长度为size的后序串
def get_post_s(size, pre_s,in_s):
	if size <= 0:
		return
	#print pre_s, in_s
	root_pos = in_s.index(pre_s[0])
	get_post_s(root_pos,pre_s[1:root_pos+1], in_s[:root_pos], pos_s)
	get_post_s(size - root_pos - 1, pre_s[root_pos+1:], in_s[root_pos+1:], pos_s) #the right tree's value should start after the left tree
	# push the root self
	#pos_s[start_index+size-1] = pre_s[0]
	global rsl
	rsl += pre_s[0]
	#print pre_s[0]

#不使用全局变量引入的话，使用一个pos_s来保存每个位置的结果，这个要注意的是，每次pre_s要加入到最后的位置，因为后序是放在在最后的，但是这个最后是相对而言的。相对某个起点来说，后序里面，肯定是先放完左子树的，再放右子树的嘛；可以自行使用上面的例子进行推演
def get_post_s_1(size, pre_s,in_s, pos_s, start_index):
	if size <= 0:
		return
	#print pre_s, in_s
	root_pos = in_s.index(pre_s[0])
	get_post_s_1(root_pos,pre_s[1:root_pos+1], in_s[:root_pos], pos_s, start_index)#start_index为相对起点
	get_post_s_1(size - root_pos - 1, pre_s[root_pos+1:], in_s[root_pos+1:], pos_s, start_index + root_pos) #the right tree's value should start after the left tree #对于相对起点，因为前的root_pos个位置都用于放左子树的内容了，所以右子树是start_index+root_pos开始的
	# push the root self 
	pos_s[start_index+size-1] = pre_s[0] #将本轮得到的根结点放在相对起点位置的最后一个位置上；


pre_s = 'DBACEGF'
in_s = 'ABCDEFG'

'''
rsl = ''
size = len(pre_s)
get_post_s(size, pre_s, in_s)
print rsl
'''

start_index = 0
size = len(pre_s)
pos_s = ['' for i in range(size)]
get_post_s_1(size, pre_s, in_s, pos_s, start_index)
print pos_s