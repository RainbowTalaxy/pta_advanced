
import Foundation

var N = Int(readLine()!)!
var M = N
var maxFact = Int(sqrt(Double(M)))

var primeList = [Bool](repeating: true, count: maxFact + 1)
var factList = [Int](repeating: 0, count: maxFact + 1)
var current = 2

while current <= maxFact {
    if primeList[current] {
        if factList[current] == 0 {
            var p = current
            while p <= maxFact {
                primeList[p] = false
                p += current
            }
            primeList[current] = true
        }
        if M % current == 0 {
            factList[current] += 1
            M /= current
        } else {
            current += 1
        }
    } else {
        current += 1
    }
}

var result = [String]()

factList.enumerated().forEach {
    if $1 == 1 {
        result.append("\($0)")
    } else if $1 != 0 {
        result.append("\($0)^\($1)")
    }
}

if result.isEmpty {
    result.append("\(N)")
}

print("\(N)=\(result.joined(separator: "*"))")
