/*
ICS 51, Lab #2

--------------------------------------------------------------------

IMPORTATNT NOTES:

- To test your code use the tests in lab2-tester.cpp

- Write your assembly code only in the marked areas.

- You are not allowed to change anything in this file except for adding your assembly code
between the lines marked with "YOUR CODE STARTS HERE" and "YOUR CODE ENDS HERE".

- This lab has to be done individually.

- Remember to fill in your name, student ID below.

- Two test images are provided to you (lena.png and authoritah.png)

- Submit ONLY your completed lab2.cpp for grading.
*/

char *yourName = "Deming Hao";
char *yourStudentID = "60943573";


/***********************************************************************************************

PART 1: Image Thresholding

- This function takes in a square sized grayscale image and applies thresholding on each pixel.
i.e. it should change pixel values according to this formula:
0xFF       if x >= threshold
0x00       if x <  threshold
- The width and height of the image are equal to dim.
- You are not allowed to define additional variables.

************************************************************************************************/
void imageThresholding(unsigned char* image, int dim, unsigned char threshold) {
	__asm
	{
		// YOUR CODE STARTS HERE
		mov eax, 0
			mov ebx, dim
			mov dh, threshold
			mov ecx, image
			imul ebx, ebx
		start_loop :
		cmp eax, ebx// if(i<dim*dim)
			jge end_loop
			mov dl, byte ptr[ecx + eax]
			cmp dl, dh
			jae elseblock
			mov byte ptr[ecx + eax], 0x00
			inc eax
			jmp start_loop
		elseblock :
		mov byte ptr[ecx + eax], 0xFF
			inc eax
			jmp start_loop
		end_loop :



		// YOUR CODE ENDS HERE
	}
}


/***********************************************************************************************

PART 2: Image Rotation

- This function rotates a square sized color image:
90 degress clockwise if direction > 0
90 degress counterclockwise if direction < 0
- If direction == 0, the image is not rotated.
- The width and height of the image are both equal to dim.
- Four variables (a0, a90, a180, a270) are defined that you may use in your implementation for
temporary data storage. You are not allowed to define additional variables.

************************************************************************************************/
void imageRotation(unsigned int* image, int dim, int direction) {
	unsigned int a0, a90, a180, a270;
	/*
	for (int row = 0; row <= (dim / 2) - 1; row++)
	{
	for (int col = row; col <= dim - 2 - row; col++)
	{
	a0 = image[(row*dim) + col];
	a90 = image[(dim-1-col)*dim+row];///stopped here
	a180 = image[(dim - 1 - row)*dim + (dim - 1 - col)];
	a270 = image[(col*dim) + (dim - 1 - row)];

	if (direction > 0)
	{
	image[(row*dim) + col] = a90;
	image[(dim - 1 - col) + row] = a180;
	image[(dim - 1 - row)*dim + (dim - 1 - col)] = a270;
	image[(col*dim) + (dim - 1 - row)] = a0;
	}
	if (direction < 0)
	{
	image[(row*dim) + col] = a270;
	image[(dim - 1 - col)*dim + row] = a0;
	image[(dim - 1 - row)*dim + (dim - 1 - col)] = a90;
	image[(col*dim) + (dim - 1 - row)] = a180;
	}
	}
	}*/
	__asm
	{
		// YOUR CODE STARTS HERE

		mov edx, direction
			cmp edx, 0 //row =0
			je end// Jump to the end (i.e, return) if direction == 0

			mov eax, 0 //i =0
		Outerloop_Row:
		mov ebx, dim
			shr ebx, 1
			dec ebx
			cmp eax, ebx  // compare row<=(dim/2)-1
			jg end
			mov ecx, eax// col=row
		interloop_col :
		mov edx, dim
			mov esi, dim
			sub edx, 2   // dim-2
			sub edx, eax // dim - row - 2
			cmp ecx, edx
			jg interloop_end
			mov edi, eax  //edi = row
			imul edi, esi  // row*dim 
			add edi, ecx  // row*dim + col 
			shl edi, 2   //each take 4 bytes in memory
			add edi, image  // edi holds the address
			mov a0, edi //mov to a0

			mov edi, dim
			dec edi     // dim -1
			sub edi, ecx //dim-1-col
			imul edi, esi // (dim-1-col) * dim
			add edi, eax
			shl edi, 2
			add edi, image
			mov a90, edi

			mov edi, dim
			dec edi  //dim -1
			sub edi, eax // dim-1-row
			imul edi, esi //(dim -1 - row) * dim 
			add edi, esi // (dim-1-row)*dim +dim
			dec edi // (dim-1-row)*dim +dim -1 
			sub edi, ecx //(dim-1-row)*dim +dim -1 -col 
			imul edi, 4
			add edi, image
			mov a180, edi

			mov edi, dim
			imul edi, ecx // dim*col 
			add edi, esi // dim*col + dim 
			dec edi  //dim*col +dim -1
			sub edi, eax //dim*col +dim -1- row
			imul edi, 4
			add edi, image
			mov a270, edi

			mov edx, direction
			cmp edx, 0
			jg another_if
			mov ebx, a0
			mov ebx, [ebx]  // ebx is i0
			mov esi, a90
			mov edi, [esi] //edi is a90
			mov[esi], ebx    //a0->a90

			mov edx, a180
			mov esi, [edx]  //esi is a180
			mov[edx], edi  // a90 ->a180 

			mov edi, a270
			mov edx, [edi] //edx is a270
			mov[edi], esi   //a180 -> a270

			mov ebx, a0
			mov[ebx], edx  // a270 ->a0 
			jmp next

		another_if :
		mov ebx, a0
			mov ebx, [ebx]
			mov esi, a270
			mov edi, [esi]
			mov[esi], ebx

			mov edx, a180
			mov esi, [edx]
			mov[edx], edi

			mov edi, a90
			mov edx, [edi]
			mov[edi], esi

			mov ebx, a0
			mov[ebx], edx


		next :
		inc ecx
			jmp interloop_col

		interloop_end :
		inc eax
			jmp Outerloop_Row


			// Iterate over the red triangle (row by row starting from top left)

			// compute index of pixel p0, find the corresponding memory address and store it in a0

			// compute index of pixel p90, find the corresponding memory address and store it in a90

			// compute index of pixel p180, find the corresponding memory address and store it in a180

			// compute index of pixel p270, find the corresponding memory address and store it in a270

			// rotationaly swap pixel values
			// direction > 0 : p0 -> p90 -> p180 -> p270 -> p0
			// direction < 0 : p0 -> p270 -> p180 -> p90 -> p0
		end:
		// YOUR CODE ENDS HERE
	}

}