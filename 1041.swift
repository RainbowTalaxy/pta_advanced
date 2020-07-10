
import Foundation

func readList() -> [Int] {
    return readLine()!.split(separator: " ").map {Int(String($0))!}
}

var lotterys = readList()
lotterys.removeFirst()

var map = [Int](repeating: 0, count: 10001)

lotterys.forEach {
    map[$0] += 1
}

for i in lotterys {
    if map[i] == 1 {
        print(i)
        exit(0)
    }
}

print("None")
