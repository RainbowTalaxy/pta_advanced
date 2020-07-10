
import Foundation

let n = Int(readLine()!)!

let values = readLine()!
    .split(separator: " ")
    .map{ Int(String($0))! }
    .sorted()

var nodes = [Int](repeating: 0, count: n)

var mark = 0
func inOrderMark(node: Int) {
    guard node >= 0 && node < n else {
        return
    }
    inOrderMark(node: node * 2 + 1)
    nodes[node] = values[mark]
    mark += 1
    inOrderMark(node: node * 2 + 2)
}

inOrderMark(node: 0)

print(nodes.map{ String($0) }.joined(separator: " "))
