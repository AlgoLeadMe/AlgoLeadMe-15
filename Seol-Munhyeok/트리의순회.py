import sys
sys.setrecursionlimit(10**6)

n = int(input())
inorder = list(map(int, input().split()))
postorder = list(map(int, input().split()))
preorder = []
inorder_index = [0] * (n+1)

for i, v in enumerate(inorder):
    inorder_index[v] = i

def get_preorder(in_start, in_end, post_start, post_end):
    if in_start > in_end or post_start > post_end:
        return
    
    root = postorder[post_end]
    preorder.append(root)
    root_index = inorder_index[root]
    left_size = root_index - in_start

    get_preorder(in_start, root_index - 1, post_start, post_start + left_size - 1)
    get_preorder(root_index + 1, in_end, post_start + left_size, post_end - 1)

get_preorder(0, n-1, 0, n-1)
print(' '.join(map(str, preorder)))
