
class AutoStateMachine{

    enum class command {START,STOP,funct};

    AutoStateMachine(){

    }
    void Run(command code[]){
        for(int i=0;i<sizeof(code);i++){
           if(RunLine(code[i]))break; 
        }
    }

    bool RunLine(command line){ //runs individual line of auto code
        switch(line){
               case command::START: break;
               case command::STOP: return false; //used for stoping mid code
            }
        return true;
    }

};