




#  Heap
 ##  Binary Heap
 Binary heap, yapısına bağlı olarak maksimum veya mininmum ögeyi elde etmek için verileri verimli şekilde depolayan eksiksiz bir binary tree'dir. Binary heap maksimum veya mininmum yığın özellik sıralamasına sahip bir binary tree'dir. Min heap veya max heap olarak da adlandırılır.
 ## Min Heap 
 Min Heap: Kökteki eleman(ağacın başlangıç elemanı), binary heap'te bulunan tüm elemanlar arasında en küçük(mininmum) olmalıdır. Aynı özellik, binary tree'deki tüm düğümler(düğüm:ağacın elemanı) için yinelemeli olarak doğru olmalıdır. Max Heap'i tam tersi olarak düşünebilirsiniz.

**Binary search tree(kısaca bst)'den farklı olarak daha küçük olan eleman sağ veya sol tarafta bulunabilir.

## Min Heap Örnekleri
       10            10
      /   \        /   \  
     20  100      15    30  
     /           / \    / \
    30          40 50  100 40

# Binary Heap'in Gösterimi
Binary Heap, tipik olarak dizilerle gösterilir.
Kök eleman Arr[0] konumunda olmalıdır.

* Arr[(i-1)/2] -----> üst düğümünü döndürür

* Arr[(2*i)+1] -----> sol alt düğümü döndürür

* Arr[(2*i)+1] ------> sağ alt düğümü döndürür

# Heap'te Kullancağımız Bazı Operatörler
getMin(): Min heap'in kök elemanını döndürür. Bu operatörün zaman karmaşıklığı O(1)'dir. Max heap olması durumunda getMax() olacaktır.

insert(): Yeni eleman eklemek O(log N) zaman alır. Ağacın sonuna eklenen yeni eleman, üst düğümden daha büyükse bir şey yapmamıza gerek yok. Aksi durumda, ihlal edilen yığın özelliğini düzeltmek için yukarı doğru hareket etmemiz gerekir. İhlal kalmayna kadar üst düğümlerle değiştirmeliyiz.

delete(): Bir elemanın silinmesi O(log N) zaman alır. decreaseKey()'i çağırarak silinecek elemanı minimum sonsuz ile değiştiriyoruz. decreaseKey()'den sonra eksi sonsuz değer köke ulaşmalıdır.

# Bir Dizi Nasıl Binary Heap'e Dönüştürülür?
0 ile n-1 aralığında yer alan i için, düğümde gerçekleşecek min/maks yığın ihlaline kadar a[i] elemanını yinelemeli olarak değiştirmemiz gerekir.
# İki Yığın Tekniği
 İki yığın tutun:
* İlk kısım için max heap,
* İkinci kısım için min heap
*Boyut olarak aralarında en fazla 1 fark olması için yığınları dengelemek gerekebilir.

# Bir Sayı Akışının Medyanını Bulmak
    // Iki yigin teknigini kullanacagiz
    // Ilk kisimda önceliği büyük sayıya vererek yigin olusturduk 
    PriorityQueue<Integer> maxHeap = new PriorityQueue<>((a, b) -> b -a);
    // Ikinci kisimda önceliği küçük sayıya vererek yigin olusturduk
    PriorityQueue<Integer> minHeap = new PriorityQueue<>();

    public void insertNum(int n) {
	// Ilk eleman
	if (minHeap.isEmpty()) {
		minHeap.add(n);
		return;
	}

	// Mininum ya da maksimum yigina yerlestirme
	Integer minSecondHalf = minHeap.peek();
	if (n >= minSecondHalf) {
		minHeap.add(n);
	} else {
		maxHeap.add(n);
	}

	// Yiginlar dengede mi?
    // Yiginlar dengede degilse bir elemani digerine aktararak dengeyi saglamamiz lazim
	if (minHeap.size() > maxHeap.size() + 1) {
		maxHeap.add(minHeap.poll());
	} else if (maxHeap.size() > minHeap.size() + 1) {
		minHeap.add(maxHeap.poll());
	}

    }
    // Son olarak medyani dondurecegiz
    public double findMedian() {
	// Cift ise
	if (minHeap.size() == maxHeap.size()) {
		return (double) (minHeap.peek() + maxHeap.peek()) / 2;
	}

	// Tek ise
	if (minHeap.size() > maxHeap.size()) {
		return minHeap.peek();
	}
	return maxHeap.peek();
    }

# Herhangi Bir Şekilde Sıralanmamış Bir Sayı Dizisindeki En Büyük Sayıyı Bulma
    // Icinde sadece k tane eleman tutan bir min heap kullanacagiz
    // Ilk k sayiyi yerlestirelim
	for (int i = 0; i < k; i++) {
		minHeap.add(nums[i]);
	}

	// Bunu dizinin geri kalanı icin de uygula
	// gecerli elemanin dizinin en kucuk elemanindan buyuk olup olmadigini kontrol et
	for (int i = k; i < nums.length; i++) {
		if (nums[i] > minHeap.peek()) {
			minHeap.poll();
			minHeap.add(nums[i]);
		}
	}

	return toList(minHeap);
    }

    public static List<Integer> toList(PriorityQueue<Integer> minHeap) {
	List<Integer> list = new ArrayList<>(minHeap.size());
	while (!minHeap.isEmpty()) {
		list.add(minHeap.poll());
	}

	return list;
    }

# Heapsort Algoritması
* Diziden maksimum bir yığın oluşturun (i n-1'den 0'a)
    1) En büyük elemanı(0'ıncı index'deki eleman) i ile değiştirin
    2) Kök elemanı doğru konuma getirerek diğer elemanları(0'dan i-1) yığınlaştırın. Bir düğümde maksimum yığın ihlali olana kadar elemanı en büyük alt düğüm ile değiştirmeye devam edin.
## Not: Binary Heap kararlıdır.

# Binary Heap Oluşturmak İçin Gereken Zaman Karmaşıklığı
Bir binary heap'i oluşturmak, O(n) ile Heapify() zaman alacaktır. Bir yığındaki elemanları alıp tek tek topladığımızda ve her adımda yığın özelliğini sağlamaya devam ettiğimizde, toplam zaman karmaşıklığı O(nlogn) olacaktır. Çünkü binary heap'in genel yapısı eksiksiz bir binary tree'dir.

# Öncelik Sırası Metodu İçin Bst yerine neden Binary Heap Tercih Ediliyor?
Maksimum ya da minimum değer için bst fazladan bir işaretçiye ihtiyaç duyar. Aksi taktirde mini veya maksimumu bulmak O(logn) zaman alır.

Bir dizi kullanarak aynı işlemi daha hızlı yapabiliriz. Aynı zaman bu bize daha fazla önbellek ve daha iyi konum bilgisi sağlar.

Binary heap'te ise O(n) zaman alır.

