
import Foundation

func readList() -> [Int] {
    return readLine()!.split(separator: " ").map {Int(String($0))!}
}

struct Range {
    let left, right: Int
    func isValid() -> Bool {
        return left <= right
    }
}

var num = readList()[0]
var preOrder = readList()

var roots = [Int]()

func isValidBST(_ range: Range) -> Bool {
//    print(roots, range.left, range.right)
    var result = true
    if range.isValid() {
        let root = preOrder[range.left]
        let subRange = Range(left: range.left + 1, right: range.right)
        if subRange.isValid() {
            var mark = subRange.right + 1
            for i in subRange.left...subRange.right {
                if preOrder[i] >= root {
                    mark = i
                    break
                }
            }
            let leftRange = Range(left: subRange.left, right: mark - 1)
            let rightRange = Range(left: mark, right: subRange.right)
            if rightRange.isValid() {
                for i in rightRange.left...rightRange.right {
                    if preOrder[i] < root {
                        result = false
                    }
                }
            }
            result = result && isValidBST(leftRange) && isValidBST(rightRange)
        }
        roots.append(root)
    }
    return result
}

func isValidBSTMirror(_ range: Range) -> Bool {
//    print(roots, range.left, range.right)
    var result = true
    if range.isValid() {
        let root = preOrder[range.left]
        let subRange = Range(left: range.left + 1, right: range.right)
        if subRange.isValid() {
            var mark = subRange.right + 1
            for i in subRange.left...subRange.right {
                if preOrder[i] < root {
                    mark = i
                    break
                }
            }
            let leftRange = Range(left: subRange.left, right: mark - 1)
            let rightRange = Range(left: mark, right: subRange.right)
            if rightRange.isValid() {
                for i in rightRange.left...rightRange.right {
                    if preOrder[i] >= root {
                        result = false
                    }
                }
            }
            result = result && isValidBSTMirror(leftRange) && isValidBSTMirror(rightRange)
        }
        roots.append(root)
    }
    return result
}

let range = Range(left: 0, right: preOrder.count - 1)

if isValidBST(range) {
    print("YES")
    print(roots.map{String($0)}.joined(separator: " "))
} else {
    roots.removeAll()
//    print("MARK")
    if isValidBSTMirror(range) {
        print("YES")
        print(roots.map{String($0)}.joined(separator: " "))
    } else {
        print("NO")
    }
}
