
import Foundation

let sentence = readLine()!
let takingStrings = readLine()!

var takingSet = Set<Character>()

for c in takingStrings {
    // 猜ASCII可视字符数量
    if takingSet.count == 92 {
        break
    }
    takingSet.insert(c)
}

sentence.forEach {
    if !takingSet.contains($0) {
        print($0, terminator: "")
    }
}
