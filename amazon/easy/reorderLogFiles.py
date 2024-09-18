class Solution:
    def reorderLogFiles(self, logs: list[str]) -> list[str]:
        let_logs_aux = {}
        dig_logs = []
        content = []
        
        for log in logs:
            l = log.split(" ")
            
            if not l[1].isnumeric():
                joined = " ".join(l[1:])
                
                if joined in let_logs_aux:
                    let_logs_aux[joined].append(l[0])
                    let_logs_aux[joined].sort()
                else:
                    let_logs_aux[joined] = [l[0]]
                content.append(joined)
            else:
                dig_logs.append(log)

        let_logs = []
        content.sort()
        
        for c in content:
            let_logs.append(let_logs_aux[c][0] + " " + c)
            let_logs_aux[c].pop(0)

        return let_logs + dig_logs
    

def main() -> None:
    logs = ["a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo","a2 act car"]

    s = Solution()

    print(s.reorderLogFiles(logs))


if __name__ == "__main__":
    main()
    