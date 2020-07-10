
import Foundation

func readList() -> [Int] {
    return readLine()!.split(separator: " ").map {Int(String($0))!}
}

var args = readList()
let nodeNum = args[0], noneLeafNum = args[1], target = args[2]

var nodes = [Set<Int>](repeating: Set<Int>(), count: nodeNum)
var values = readList()

(0..<noneLeafNum).forEach {_ in
    args = readList()
    let root = args.removeFirst(), _ = args.removeFirst()
    for sub in args {
        nodes[root].insert(sub)
    }
}

func DFS(root: Int, sum: Int, list: [Int]) {
    if sum == target {
        if nodes[root].isEmpty {
            print(list.map { String($0) }.joined(separator: " "))
        }
    } else if sum < target {
        for sub in nodes[root].sorted(by: { values[$0] > values[$1] }) {
            DFS(root: sub, sum: sum + values[sub], list: list + [values[sub]])
        }
    }
}

DFS(root: 0, sum: values[0], list: [values[0]])
