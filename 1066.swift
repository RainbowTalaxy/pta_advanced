
import Foundation

class AVLTree<T: Comparable> {
    
    enum Balance {
        case LEFT_HEAVY, LEFT_HEAVY_BUT_BALANCED, COMPLETE_BLANCED, RIGHT_HEAVY_BUT_BALANCED, RIGHT_HEAVY
    }
    
    class Node {
        
        var parent, left, right: Node?
        var height = 1
        var key: T
        
        init(withKey key: T) {
            self.key = key
        }
        var balanceFactor: Balance {
            switch (left?.height ?? 0) - (right?.height ?? 0) {
            case 2...:
                return .LEFT_HEAVY
            case 1:
                return .LEFT_HEAVY_BUT_BALANCED
            case 0:
                return .COMPLETE_BLANCED
            case -1:
                return .RIGHT_HEAVY_BUT_BALANCED
            default:
                return .RIGHT_HEAVY
            }
        }
        var isLeftChild: Bool {
            return self === parent?.left
        }
        var isRightChild: Bool {
            return self === parent?.right
        }
        
        func rotateLeft() {
            let oldRoot = self, newRoot = right
            newRoot?.left?.parent = oldRoot
            oldRoot.right = newRoot?.left
            if oldRoot.isLeftChild {
                oldRoot.parent?.left = newRoot
            } else if oldRoot.isRightChild {
                oldRoot.parent?.right = newRoot
            }
            newRoot?.parent = oldRoot.parent
            oldRoot.parent = newRoot
            newRoot?.left = oldRoot
            oldRoot.updateHeight()
            newRoot?.updateHeight()
        }
        
        func rotateRight() {
            let oldRoot = self, newRoot = left
            newRoot?.right?.parent = oldRoot
            oldRoot.left = newRoot?.right
            if oldRoot.isLeftChild {
                oldRoot.parent?.left = newRoot
            } else if oldRoot.isRightChild {
                oldRoot.parent?.right = newRoot
            }
            newRoot?.parent = oldRoot.parent
            oldRoot.parent = newRoot
            newRoot?.right = oldRoot
            oldRoot.updateHeight()
            newRoot?.updateHeight()
        }
        
        func updateHeight() {
            height = max(left?.height ?? 0, right?.height ?? 0) + 1
        }
        
        func repair() {
            switch balanceFactor {
            case .LEFT_HEAVY:
                switch left!.balanceFactor {
                case .LEFT_HEAVY_BUT_BALANCED:
                    rotateRight()
                case .RIGHT_HEAVY_BUT_BALANCED:
                    left?.rotateLeft()
                    rotateRight()
                default:
                    break
                }
            case .RIGHT_HEAVY:
                switch right!.balanceFactor {
                case .RIGHT_HEAVY_BUT_BALANCED:
                    rotateLeft()
                case .LEFT_HEAVY_BUT_BALANCED:
                    right?.rotateRight()
                    rotateLeft()
                default:
                    break
                }
            default:
                break
            }
            updateHeight()
            parent?.repair()
        }
        
    }
    
    var root: Node? = nil
    
    private func updateRoot(withNode node: Node?) {
        root = node
        while let newRoot = root?.parent {
            root = newRoot
        }
    }
    
    func insert(withKey key: T) {
        let newNode = Node(withKey: key)
        if var current = root {
            while true {
                if key < current.key {
                    if let child = current.left {
                        current = child
                    } else {
                        current.left = newNode
                        newNode.parent = current
                        break
                    }
                } else if key > current.key {
                    if let child = current.right {
                        current = child
                    } else {
                        current.right = newNode
                        newNode.parent = current
                        break
                    }
                } else {
                    return
                }
            }
        } else {
            root = newNode
        }
        newNode.repair()
        updateRoot(withNode: newNode)
    }
    
}

let n = Int(readLine()!)!
let list = readLine()!.split(separator: " ").map{ Int(String($0))! }

var tree = AVLTree<Int>()

for i in list {
    tree.insert(withKey: i)
}

print(tree.root?.key ?? 0)
