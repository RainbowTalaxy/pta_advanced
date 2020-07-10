
import Foundation

var readInt: Int { return Int(readLine()!)! }
var readList: [Int] { return readLine()!.split(separator: " ").map { return Int(String($0))! } }

var intList = readList
var vNum = intList[0], eNum = intList[1]
var graph = [[Bool]](repeating: [Bool](repeating: false, count: 201), count: 201)

for _ in 0..<eNum {
    intList = readList
    graph[intList[0]][intList[1]] = true
    graph[intList[1]][intList[0]] = true
}

var qNum = readInt
var result = [Bool]()

loop:
for _ in 0..<qNum {
    intList = readList
    let n = intList[0]
    if n == vNum + 1 {
        var set = Set<Int>()
        for i in 2...n {
            set.insert(intList[i])
            if !graph[intList[i - 1]][intList[i]] {
                result.append(false)
                continue loop
            }
        }
        if set.count != vNum || intList[1] != intList[n] {
            result.append(false)
            continue loop
        }
        result.append(true)
    } else {
        result.append(false)
    }
}

result.forEach {
    print($0 ? "YES" : "NO")
}
