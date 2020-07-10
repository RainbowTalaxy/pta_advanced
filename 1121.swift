
import Foundation

var readInt: Int { return Int(readLine()!)! }
var readList: [Int] { return readLine()!.split(separator: " ").map { return Int(String($0))! } }

func f(_ i: Int) -> String {
    switch i {
    case 5: return ""
    case 4: return "0"
    case 3: return "00"
    case 2: return "000"
    case 1: return "0000"
    case 0: return "00000"
    default:return ""
    }
}

var relation = [Int](repeating: -1, count: 100000)

for _ in 0..<readInt {
    let couple = readList
    relation[couple[0]] = couple[1]
    relation[couple[1]] = couple[0]
}

var checkNumber = readInt
var checkList = readList
var counter = [Int](repeating: 0, count: 100000)

for n in checkList {
    counter[n] += 1
    if relation[n] != -1 {
        counter[relation[n]] += 2
    }
}
var count = 0

for i in 0..<100000 {
    if counter[i] == 1 {
        count += 1
    }
}

var flag = false
print(count)
for i in 0..<100000 {
    if counter[i] == 1 {
        if !flag {
            flag = true
        } else {
            print(terminator: " ")
        }
        let s = String(i)
        print(f(s.count) + s, terminator: "")
    }
}