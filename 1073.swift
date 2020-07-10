
import Foundation

var a = [Int]()

var args = readLine()!.split(separator: "E").map{String($0)}

var flag = args[0].removeFirst() == "+"
var number = args[0].split(separator: ".").map{String($0)}
var left = Array<Character>(number[0])
var right = Array<Character>(number[1])
var exponet = Int(args[1])!

func giveRight() -> Character {
    let last = left.removeLast()
    if left.isEmpty {
        left.append("0")
    }
    return last
}

func receiveRight(char: Character) {
    left.append(char)
}

func giveLeft() -> Character {
    var first: Character = "0"
    if !right.isEmpty {
        first = right.removeFirst()
    }
    return first
}

func receiveLeft(char: Character) {
    right.insert(char, at: 0)
}

if exponet > 0 {
    (0..<exponet).forEach {_ in
        receiveRight(char: giveLeft())
    }
} else if exponet < 0 {
    (exponet..<0).forEach {_ in
        receiveLeft(char: giveRight())
    }
}

print((flag ? "" : "-") + String(left) + (right.isEmpty ? "" : ".") + String(right))
