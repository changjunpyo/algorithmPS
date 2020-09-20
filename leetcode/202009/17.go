
var dx = [4]int {-1, 0 , 1 ,0}
var dy = [4]int {0, 1, 0, -1}

type Robot struct {
    x,y int
    dir int
}

func (r *Robot) moveForward(){
    r.x ,r.y = r.x +dx[r.dir] ,r.y+ dy[r.dir]
}
func (r *Robot) TurnRight(){
    r.dir = (r.dir +1) %4   
}
func (r *Robot) TurnLeft(){
    r.dir = r.dir-1
    if r.dir <0{
        r.dir +=4
    }
}

func (r *Robot) moveByInstruction(instruction byte){
    if instruction == 'G'{
        r.moveForward()
    } else if instruction =='R'{
        r.TurnRight()
    } else if instruction =='L'{
        r.TurnLeft()
    }
}


func isRobotBounded(instructions string) bool {
    r := Robot{0,0,0}
    for i:=0; i<len(instructions)*4; i++{
        r.moveByInstruction(instructions[i%len(instructions)])
    }
    return r.x == 0 && r.y == 0
}
