import sys
sys.setrecursionlimit(10**6)

n = int(input())
inorder = list(map(int, input().split()))
postorder = list(map(int, input().split()))
preorder = []

# 빠른 인덱스 조회용 (값 → 인오더 위치)
inorder_index = [0] * (n + 1)
for i, v in enumerate(inorder):
    inorder_index[v] = i

def get_preorder(in_start, in_end, post_start, post_end, depth=0):
    indent = '  ' * depth  # 깊이에 따라 들여쓰기
    print(f"{indent}call: in=({in_start}, {in_end}), post=({post_start}, {post_end})")

    if in_start > in_end or post_start > post_end:
        print(f"{indent}return (base case)")
        return

    root = postorder[post_end]
    preorder.append(root)
    print(f"{indent}root = {root}")

    root_index = inorder_index[root]
    left_size = root_index - in_start
    print(f"{indent}root_index = {root_index}, left_size = {left_size}")

    # 왼쪽 서브트리
    get_preorder(in_start, root_index - 1, post_start, post_start + left_size - 1, depth + 1)
    # 오른쪽 서브트리
    get_preorder(root_index + 1, in_end, post_start + left_size, post_end - 1, depth + 1)

get_preorder(0, n - 1, 0, n - 1)
print("preorder =", ' '.join(map(str, preorder)))
