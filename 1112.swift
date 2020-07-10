
import Foundation

var readInt: Int { return Int(readLine()!)! }

var time = readInt
var sentence = Array(readLine()!)

var isStucked = [Character: Bool]()
var preLetter: Character?

var count = 0
for i in 0 ..< sentence.count {
   if count > 0 {
       count -= 1
       continue
   }
   if i + time <= sentence.count && String(sentence[i..<i + time]) == String(repeating: sentence[i], count: time) {
       if let flag = isStucked[sentence[i]] {
           isStucked[sentence[i]] = flag && true
       } else {
           isStucked[sentence[i]] = true
       }
       count += time - 1
   } else {
       isStucked[sentence[i]] = false
   }
}

var result = "", same = ""
count = 0
for letter in sentence {
   if count > 0 {
       count -= 1
       continue
   }
   if isStucked[letter]! {
       count += time - 1
       if !same.contains(letter) {
           same.append(letter)
       }
   }
   result.append(letter)
}

print(same)
print(result)

