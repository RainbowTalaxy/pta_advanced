
import Foundation

func toList(str: String) -> [Int] {
    return str.split(separator: ".").map {Int(String($0))!}
}

var args = readLine()!.split(separator: " ").map{ String($0) }
var A = toList(str: args[0])
var B = toList(str: args[1])

(0..<3).forEach {
    A[$0] += B[$0]
}

A[1] += A[2] / 29
A[2] %= 29

A[0] += A[1] / 17
A[1] %= 17
 
print(A.map{ $0.description }.joined(separator: "."))
