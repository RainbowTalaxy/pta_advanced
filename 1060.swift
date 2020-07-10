
import Foundation

func readList() -> [String] {
    return readLine()!.split(separator: " ").map {String($0)}
}

struct DoubleEx {
    var base: String
    var ex: Int
    
    init(withDoubleString double: String) {
        var slices = double.split(separator: ".").map {String($0)}
        var base = "", ex = 0
        while let first = slices[0].first {
            if first == "0" {
                slices[0].removeFirst()
            } else {
                break
            }
        }
        if slices[0].isEmpty {
            slices[0] = "0"
        }
        if slices[0] == "0" {
            if slices.count == 2 {
                while let first = slices[1].first {
                    if first == "0" {
                        slices[1].removeFirst()
                        ex -= 1
                    } else {
                        break
                    }
                }
                if slices[1].isEmpty {
                    base = "0"
                    ex = 0
                } else {
                    base = slices[1]
                }
            } else {
                base = "0"
                ex = 0
            }
        } else {
            if slices.count == 1 {
                base = slices[0]
            } else {
                base = slices[0] + slices[1]
            }
            ex = slices[0].count
        }
        self.base = base
        self.ex = ex
    }
    
    func show(withWidth width: Int) -> String {
        if base.count < width {
            return "0." + base + String(repeating: "0", count: width - base.count) + "*10^\(ex)"
        } else {
            return "0." + Array(base)[0..<width] + "*10^\(ex)"
        }
    }
}

var args = readList()
let width = Int(args[0])!
var a = DoubleEx(withDoubleString: args[1]).show(withWidth: width)
var b = DoubleEx(withDoubleString: args[2]).show(withWidth: width)

if a == b {
    print("YES \(a)")
} else {
    print("NO \(a) \(b)")
}

/*
 0.0123
    0   0123
    0.123 * 10^-1
 
 12
    12  -
    0.12 * 10^2
 
 12.3
    12  3
    0.123 * 10^2
 
 0
    0   -
    0 * 10^0
 
 0.00
    0   00
    
 还有前导0需要去除
 */
