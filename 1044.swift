
import Foundation

func readList() -> [Int] {
    return readLine()!.split(separator: " ").map {Int(String($0))!}
}

var args = readList()
let num = args[0], ex = args[1]
var coins = readList()

struct Info {
    var leftSum, rightSum: Int
}

var infos = [Info](repeating: Info(leftSum: 0, rightSum: 0), count: num + 1)

var count = 0, sum = 0

for i in 0..<coins.count {
    count += coins[i]
    infos[i + 1].leftSum = count
}

sum = count
count = 0
for i in stride(from: infos.count - 2, to: -1, by: -1) {
    count += coins[i]
    infos[i].rightSum = count
}

// p[0] refers to start, p[1] refers to end
var p = [0, 0]

var min = Int.max, flag = true
if sum >= ex {
    while p[1] <= num {
        let value = sum - (infos[p[0]].leftSum + infos[p[1]].rightSum)
        if value < ex {
            p[1] += 1
        } else if value > ex {
            if value < min {
                min = value
            }
            p[0] += 1
        } else {
            flag = false
            print("\(p[0] + 1)-\(p[1])")
            p[0] += 1
        }
    }
    if flag {
        p = [0, 0]
        while p[1] <= num {
            let value = sum - (infos[p[0]].leftSum + infos[p[1]].rightSum)
            if value < min {
                p[1] += 1
            } else if value > min {
                p[0] += 1
            } else {
                flag = false
                print("\(p[0] + 1)-\(p[1])")
                p[0] += 1
            }
        }
    }
}
