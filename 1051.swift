
import Foundation

func readList() -> [Int] {
    return readLine()!.split(separator: " ").map {Int(String($0))!}
}

let args = readList()
let capacity = args[0], num = args[1], queryNum = args[2]

func isValidPop(list: [Int]) -> Bool {
    var stack = [Int](), queue = [Int]()
    for current in list.reversed() {
        while current < stack.last ?? 0 {
            queue.append(stack.removeLast())
        }
        if stack.count < capacity {
            stack.append(current)
        } else {
            return false
        }
    }
    queue += stack.reversed()
    var pre = num
    for current in queue {
        if current > pre {
            return false
        } else {
            pre = current
        }
    }
    return true
}

(0..<queryNum).forEach {_ in
    let list = readList()
    print(isValidPop(list: list) ? "YES" : "NO")
}
