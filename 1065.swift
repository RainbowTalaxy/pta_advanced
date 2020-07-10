
import Foundation

let n = Int(readLine()!)!

struct Big {
    static let limit: Int64 = 1000000000
    var a, b: Int64
    init(n: Int64) {
        b = n / Big.limit
        a = n % Big.limit
    }
    mutating func add(n: Big) {
        a += n.a
        b += n.b
        b += a / Big.limit
        a %= Big.limit
    }
    mutating func toggle() -> Big {
        a *= -1
        b *= -1
        return self
    }
    func isPositive() -> Bool {
        return a > 0 || b > 0
    }
}

for i in 1...n {
    let nums = readLine()!.split(separator: " ")
        .map{ Int64(String($0))! }
    var num = Big(n: nums[0])
    num.add(n: Big(n: nums[1]))
    var c = Big(n: nums[2])
    num.add(n: c.toggle())
    print("Case #\(i): \(num.isPositive())")
}
