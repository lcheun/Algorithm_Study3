import java.util.*;
import java.io.*;

public class Main{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        ArrayList<String> dict = new ArrayList<>();
        for(int i=0; i<N; i++){
            char[] tmp = br.readLine().toCharArray();
            for(int j=0; j<tmp.length; j++){
                if(tmp[j] == 'n' && j<tmp.length-1 && tmp[j+1]=='g'){
                    tmp[j] = 'o';
                } else if(tmp[j] == 'k'){
                    tmp[j] = 'c';
                } else if(tmp[j] == 'o'){
                    tmp[j] = 'p';
                } else if(tmp[j] == 'p'){
                    tmp[j] = 'q';
                }
            }
            dict.add(new String(tmp));
        }
        
        Collections.sort(dict);
        
        StringBuilder ans = new StringBuilder();
        for(int i=0; i<N; i++){
            char[] tmp = dict.get(i).toCharArray();
            for(int j=0; j<tmp.length; j++){
                if(tmp[j] == 'c'){
                    ans.append('k');
                } else if(tmp[j] == 'o'){
                    ans.append("ng"); j++;
                } else if(tmp[j] == 'p'){
                    ans.append('o');
                } else if(tmp[j] == 'q'){
                    ans.append('p');
                } else{
                    ans.append(tmp[j]);
                }
            }
            ans.append("\n");
        }
        
        System.out.println(ans);
    }
}
