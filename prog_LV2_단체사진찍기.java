/*
7자리로 가능한 모든 순열을 만들고
문제에 주어진 조건을 만족하는지 비교하며
만족하면 answer++
*/
class Solution {
    private String[] friends = {"A","C","F","J"
                                    ,"M","N","R","T"};
    private int answer = 0;
    public int solution(int n, String[] data) {
        
        
        boolean[] isVisited = new boolean[8];
        dfs("",isVisited,data);
        System.out.println(answer);
        return answer;
    }
    private void dfs(String names, boolean[] isVisited, String[] datas){
        if(names.length() == 7 ){
            if(check(names,datas)){
                answer++;
            }
            return;
        }
        for(int i=0; i<8; i++){
            if(!isVisited[i]){
                isVisited[i] = true;
                String name = names + friends[i];
                dfs(name,isVisited,datas);
                isVisited[i] = false;
            }
        }
    }
    private boolean check(String names, String[] datas){
        for(String data : datas){
            int position1 = names.indexOf(data.charAt(0));
            int position2 = names.indexOf(data.charAt(2));
            char op = data.charAt(3);
            int index = data.charAt(4) - '0';
            if(op=='='){
                if(!(Math.abs(position1 - position2)==index+1)) return false;}
            else if (op == '>'){
                if(!(Math.abs(position1-position2)>index+1)) return false;}
             else if(op == '<'){
                 if(!(Math.abs(position1-position2)<index+1))return false;
             }   
            }
        return true;
    }
}
