
import Foundation

func readList() -> [Int] {
    return readLine()!.split(separator: " ").map {Int(String($0))!}
}

let type = ["S", "H", "C", "D"]

var list = [String]()

type.forEach {
    for i in 1...13 {
        list.append($0 + i.description)
    }
}
list.append(contentsOf: ["J1", "J2"])

let num = readList()[0]
let order = readList()

(0..<num).forEach {_ in
    var next = list
    order.enumerated().forEach {
        next[$0.element - 1] = list[$0.offset]
    }
    list = next
}

print(list.joined(separator: " "))
