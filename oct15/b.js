for (i=2;i<1000000;i++) {
			var i2 = i;
			var b = [];
			for (var k = 2;k<=Math.sqrt(i2);) {
				if (i2%k==0) {
					i2/=k;
					b.push(k);
				} else k++;
			}
			b.push(i2);
			for (j in b) {
				if ((b[j]-1)%4 == 0) {
					console.log(i); break;
				}
			}
}
