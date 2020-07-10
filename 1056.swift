
import Foundation

func readList() -> [Int] {
    return readLine()!.split(separator: " ").map {Int(String($0))!}
}

typealias Info = (Int, Int)

var args = readList()
let pNum = args[0], gNum = args[1]

var list = readList()
var initOrder = readList()

// refers to (ID, value)
var order = [Info](repeating: (0, 0), count: pNum)
var rank = [Int](repeating: 0, count: pNum)

for (i, o) in initOrder.enumerated() {
    order[i] = (o, list[o])
}

func grouper(withGroup group: [Info], andSpan span: Int) -> [[Info]] {
    var result = [[Info]]()
    var aGroup = [Info]()
    for element in group {
        aGroup.append(element)
        if aGroup.count == span {
            result.append(aGroup)
            aGroup.removeAll()
        }
    }
    if !aGroup.isEmpty {
        result.append(aGroup)
    }
    return result
}

func reduser(withGroup groups: [[Info]]) -> [Info] {
    var result = [Info]()
    let num = groups.count + 1
    for group in groups {
        for (id, _) in group {
            rank[id] = num
        }
        if let maxn = group.max(by: {$0.1 < $1.1}) {
            result.append(maxn)
        }
    }
    return result
}

while order.count > 1 {
    order = reduser(withGroup: grouper(withGroup: order, andSpan: gNum))
}

rank[order[0].0] = 1

print(rank.map{String($0)}.joined(separator: " "))
