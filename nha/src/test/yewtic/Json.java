package test.yewtic;

import net.sf.json.JSONObject;

public class Json {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		JSONObject json = JSONObject.fromObject("{abc:1}");
		String str = json.toString();
		System.out.println(str);
	}

}
