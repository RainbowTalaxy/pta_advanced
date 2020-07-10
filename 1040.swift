
import Foundation

var sentence = Array(readLine()!)

var M = [[Bool]](
    repeating: [Bool](repeating: false, count: sentence.count),
    count: sentence.count
)

var result = 0
for len in 1...sentence.count {
    for i in 0...(sentence.count - len) {
        let j = i + len - 1
        if sentence[i] == sentence[j] && (j - i < 2 || M[i + 1][j - 1]) {
            M[i][j] = true
            result = len
        }
    }
}

print(result)
