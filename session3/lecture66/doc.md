# 트리 순회

보통은 이진트리를 기반으로 설명이 되지만, 대부분의 트리에서 확장 가능하다

## 후위 순회

자식 노드부터 탐색을 하고, 자신을 탐색한다.

```
postorder( node )
  if (node.visited == false)
    postorder( node->left )
    postorder( node->right )
    node.visited = true
```

## 전위 순회

자신부터 탐색을 하고, 자식 노드들을 탐색한다.

```
preorder( node )
  if (node.visited == false)
    node.visited = true
    preorder( node->left )
    preorder( node->right )
```

## 중위 순회

왼쪽 -> 자신 -> 오른쪽 순으로 방문하는 순서로 탐색한다.

```
inorder( node )
  if (node.visited == false)
    inorder( node->left )
    node.visited = true
    inorder( node->right )
```

## 레벨 순회
레벨 순회는 다른 용어로 BFS 이다
