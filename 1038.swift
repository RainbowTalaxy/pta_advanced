
import Foundation

func readList() -> [String] {
    return readLine()!.split(separator: " ").map {String($0)}
}

var list = readList()
list.removeFirst()

var result = list.sorted { (s1, s2) in
    return s1 + s2 < s2 + s1
}.joined()

while result.first ?? "1" == "0" {
    result.removeFirst()
}

print(result.isEmpty ? 0 : result)
