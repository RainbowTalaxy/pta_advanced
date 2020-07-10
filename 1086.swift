
import Foundation

class Tree {
    var value: Int
    var left, right: Tree?
    init(_ value: Int) {
        self.value = value
    }
}

enum Record {
    indirect case push(Int)
    case pop
}

var records = [Record]()

struct Range {
    let left, right: Int
    var isValid: Bool {
        return left >= right
    }
    func getRange() -> (Range?, Range?) {
        var pushCount = 0, popCount = 0
        for i in left + 1..<right {
            switch records[i] {
            case .push(_):  pushCount += 1
            case .pop:      popCount += 1
            }
            if popCount > pushCount {
                return (Range(left: left + 1, right: i), Range(left: i + 1, right: right))
            }
        }
        return (nil, nil)
    }
    func getTree() -> Tree? {
        if isValid {
            return nil
        } else {
            switch records[left] {
            case .push(let value):
                let tree = Tree(value)
                let (left, right) = getRange()
                tree.left = left?.getTree()
                tree.right = right?.getTree()
                return tree
            default:
                return nil
            }
        }
    }
}

var flag = true

extension Tree {
    func postTravel() {
        left?.postTravel()
        right?.postTravel()
        flag ? flag = false : print(terminator: " ")
        print(value, terminator: "")
    }
}

let n = Int(readLine()!)!

for _ in 0 ..< n * 2 {
    let s = readLine()!
    if s.hasPrefix("Push") {
        let value = String(s[s.index(s.startIndex, offsetBy: 5)...])
        records.append(Record.push(Int(value)!))
    } else {
        records.append(Record.pop)
    }
}

Range(left: 0, right: n * 2).getTree()?.postTravel()
