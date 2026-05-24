"""AVL Tree interaktiv - fut numra dhe shiko si ndryshon pema."""


class Node:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None
        self.height = 1


def height(node):
    return node.height if node else 0


def balance(node):
    return height(node.left) - height(node.right) if node else 0


def update_height(node):
    node.height = 1 + max(height(node.left), height(node.right))


def right_rotate(y):
    x = y.left
    y.left = x.right
    x.right = y
    update_height(y)
    update_height(x)
    return x


def left_rotate(x):
    y = x.right
    x.right = y.left
    y.left = x
    update_height(x)
    update_height(y)
    return y


def insert(node, value):
    if node is None:
        return Node(value)
    if value < node.value:
        node.left = insert(node.left, value)
    elif value > node.value:
        node.right = insert(node.right, value)
    else:
        return node

    update_height(node)
    bf = balance(node)

    if bf > 1 and value < node.left.value:  # LL
        return right_rotate(node)
    if bf < -1 and value > node.right.value:  # RR
        return left_rotate(node)
    if bf > 1 and value > node.left.value:  # LR
        node.left = left_rotate(node.left)
        return right_rotate(node)
    if bf < -1 and value < node.right.value:  # RL
        node.right = right_rotate(node.right)
        return left_rotate(node)
    return node


def print_tree(node, prefix="", is_left=True):
    if node is None:
        return
    if node.right:
        print_tree(node.right, prefix + ("│   " if is_left else "    "), False)
    print(prefix + ("└── " if is_left else "┌── ") + str(node.value))
    if node.left:
        print_tree(node.left, prefix + ("    " if is_left else "│   "), True)


# ====== Programi interaktiv ======
root = None
print("AVL Tree - shkruaj numra (ose 'q' për të dalë)\n")

while True:
    x = input("Numri: ").strip()
    if x.lower() == "q":
        break
    if not x.lstrip("-").isdigit():
        print("Shkruaj një numër të plotë.\n")
        continue

    root = insert(root, int(x))
    print()
    print_tree(root)
    print(f"Lartësia: {height(root)}\n")
