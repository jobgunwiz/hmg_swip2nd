
main_opt:     file format elf64-x86-64


Disassembly of section .init:

0000000000000570 <_init>:
 570:	48 83 ec 08          	sub    $0x8,%rsp
 574:	48 8b 05 6d 0a 20 00 	mov    0x200a6d(%rip),%rax        # 200fe8 <__gmon_start__>
 57b:	48 85 c0             	test   %rax,%rax
 57e:	74 02                	je     582 <_init+0x12>
 580:	ff d0                	callq  *%rax
 582:	48 83 c4 08          	add    $0x8,%rsp
 586:	c3                   	retq   

Disassembly of section .plt:

0000000000000590 <.plt>:
 590:	ff 35 22 0a 20 00    	pushq  0x200a22(%rip)        # 200fb8 <_GLOBAL_OFFSET_TABLE_+0x8>
 596:	ff 25 24 0a 20 00    	jmpq   *0x200a24(%rip)        # 200fc0 <_GLOBAL_OFFSET_TABLE_+0x10>
 59c:	0f 1f 40 00          	nopl   0x0(%rax)

00000000000005a0 <__stack_chk_fail@plt>:
 5a0:	ff 25 22 0a 20 00    	jmpq   *0x200a22(%rip)        # 200fc8 <__stack_chk_fail@GLIBC_2.4>
 5a6:	68 00 00 00 00       	pushq  $0x0
 5ab:	e9 e0 ff ff ff       	jmpq   590 <.plt>

00000000000005b0 <__printf_chk@plt>:
 5b0:	ff 25 1a 0a 20 00    	jmpq   *0x200a1a(%rip)        # 200fd0 <__printf_chk@GLIBC_2.3.4>
 5b6:	68 01 00 00 00       	pushq  $0x1
 5bb:	e9 d0 ff ff ff       	jmpq   590 <.plt>

Disassembly of section .plt.got:

00000000000005c0 <__cxa_finalize@plt>:
 5c0:	ff 25 32 0a 20 00    	jmpq   *0x200a32(%rip)        # 200ff8 <__cxa_finalize@GLIBC_2.2.5>
 5c6:	66 90                	xchg   %ax,%ax

Disassembly of section .text:

00000000000005d0 <main>:
 5d0:	48 83 ec 18          	sub    $0x18,%rsp
 5d4:	48 8d 35 09 02 00 00 	lea    0x209(%rip),%rsi        # 7e4 <_IO_stdin_used+0x4>
 5db:	bf 01 00 00 00       	mov    $0x1,%edi
 5e0:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
 5e7:	00 00 
 5e9:	48 89 44 24 08       	mov    %rax,0x8(%rsp)
 5ee:	31 c0                	xor    %eax,%eax
 5f0:	c7 44 24 04 04 00 00 	movl   $0x4,0x4(%rsp)
 5f7:	00 
 5f8:	8b 44 24 04          	mov    0x4(%rsp),%eax
 5fc:	48 8d 4c 24 04       	lea    0x4(%rsp),%rcx
 601:	83 c0 06             	add    $0x6,%eax
 604:	89 44 24 04          	mov    %eax,0x4(%rsp)
 608:	8b 54 24 04          	mov    0x4(%rsp),%edx
 60c:	31 c0                	xor    %eax,%eax
 60e:	e8 9d ff ff ff       	callq  5b0 <__printf_chk@plt>
 613:	8b 44 24 04          	mov    0x4(%rsp),%eax
 617:	8b 54 24 04          	mov    0x4(%rsp),%edx
 61b:	48 8d 35 d5 01 00 00 	lea    0x1d5(%rip),%rsi        # 7f7 <_IO_stdin_used+0x17>
 622:	31 c0                	xor    %eax,%eax
 624:	bf 01 00 00 00       	mov    $0x1,%edi
 629:	83 c2 0a             	add    $0xa,%edx
 62c:	e8 7f ff ff ff       	callq  5b0 <__printf_chk@plt>
 631:	48 8b 44 24 08       	mov    0x8(%rsp),%rax
 636:	64 48 33 04 25 28 00 	xor    %fs:0x28,%rax
 63d:	00 00 
 63f:	75 05                	jne    646 <main+0x76>
 641:	48 83 c4 18          	add    $0x18,%rsp
 645:	c3                   	retq   
 646:	e8 55 ff ff ff       	callq  5a0 <__stack_chk_fail@plt>
 64b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000000650 <_start>:
 650:	31 ed                	xor    %ebp,%ebp
 652:	49 89 d1             	mov    %rdx,%r9
 655:	5e                   	pop    %rsi
 656:	48 89 e2             	mov    %rsp,%rdx
 659:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
 65d:	50                   	push   %rax
 65e:	54                   	push   %rsp
 65f:	4c 8d 05 6a 01 00 00 	lea    0x16a(%rip),%r8        # 7d0 <__libc_csu_fini>
 666:	48 8d 0d f3 00 00 00 	lea    0xf3(%rip),%rcx        # 760 <__libc_csu_init>
 66d:	48 8d 3d 5c ff ff ff 	lea    -0xa4(%rip),%rdi        # 5d0 <main>
 674:	ff 15 66 09 20 00    	callq  *0x200966(%rip)        # 200fe0 <__libc_start_main@GLIBC_2.2.5>
 67a:	f4                   	hlt    
 67b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000000680 <deregister_tm_clones>:
 680:	48 8d 3d 89 09 20 00 	lea    0x200989(%rip),%rdi        # 201010 <__TMC_END__>
 687:	55                   	push   %rbp
 688:	48 8d 05 81 09 20 00 	lea    0x200981(%rip),%rax        # 201010 <__TMC_END__>
 68f:	48 39 f8             	cmp    %rdi,%rax
 692:	48 89 e5             	mov    %rsp,%rbp
 695:	74 19                	je     6b0 <deregister_tm_clones+0x30>
 697:	48 8b 05 3a 09 20 00 	mov    0x20093a(%rip),%rax        # 200fd8 <_ITM_deregisterTMCloneTable>
 69e:	48 85 c0             	test   %rax,%rax
 6a1:	74 0d                	je     6b0 <deregister_tm_clones+0x30>
 6a3:	5d                   	pop    %rbp
 6a4:	ff e0                	jmpq   *%rax
 6a6:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
 6ad:	00 00 00 
 6b0:	5d                   	pop    %rbp
 6b1:	c3                   	retq   
 6b2:	0f 1f 40 00          	nopl   0x0(%rax)
 6b6:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
 6bd:	00 00 00 

00000000000006c0 <register_tm_clones>:
 6c0:	48 8d 3d 49 09 20 00 	lea    0x200949(%rip),%rdi        # 201010 <__TMC_END__>
 6c7:	48 8d 35 42 09 20 00 	lea    0x200942(%rip),%rsi        # 201010 <__TMC_END__>
 6ce:	55                   	push   %rbp
 6cf:	48 29 fe             	sub    %rdi,%rsi
 6d2:	48 89 e5             	mov    %rsp,%rbp
 6d5:	48 c1 fe 03          	sar    $0x3,%rsi
 6d9:	48 89 f0             	mov    %rsi,%rax
 6dc:	48 c1 e8 3f          	shr    $0x3f,%rax
 6e0:	48 01 c6             	add    %rax,%rsi
 6e3:	48 d1 fe             	sar    %rsi
 6e6:	74 18                	je     700 <register_tm_clones+0x40>
 6e8:	48 8b 05 01 09 20 00 	mov    0x200901(%rip),%rax        # 200ff0 <_ITM_registerTMCloneTable>
 6ef:	48 85 c0             	test   %rax,%rax
 6f2:	74 0c                	je     700 <register_tm_clones+0x40>
 6f4:	5d                   	pop    %rbp
 6f5:	ff e0                	jmpq   *%rax
 6f7:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
 6fe:	00 00 
 700:	5d                   	pop    %rbp
 701:	c3                   	retq   
 702:	0f 1f 40 00          	nopl   0x0(%rax)
 706:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
 70d:	00 00 00 

0000000000000710 <__do_global_dtors_aux>:
 710:	80 3d f9 08 20 00 00 	cmpb   $0x0,0x2008f9(%rip)        # 201010 <__TMC_END__>
 717:	75 2f                	jne    748 <__do_global_dtors_aux+0x38>
 719:	48 83 3d d7 08 20 00 	cmpq   $0x0,0x2008d7(%rip)        # 200ff8 <__cxa_finalize@GLIBC_2.2.5>
 720:	00 
 721:	55                   	push   %rbp
 722:	48 89 e5             	mov    %rsp,%rbp
 725:	74 0c                	je     733 <__do_global_dtors_aux+0x23>
 727:	48 8b 3d da 08 20 00 	mov    0x2008da(%rip),%rdi        # 201008 <__dso_handle>
 72e:	e8 8d fe ff ff       	callq  5c0 <__cxa_finalize@plt>
 733:	e8 48 ff ff ff       	callq  680 <deregister_tm_clones>
 738:	c6 05 d1 08 20 00 01 	movb   $0x1,0x2008d1(%rip)        # 201010 <__TMC_END__>
 73f:	5d                   	pop    %rbp
 740:	c3                   	retq   
 741:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
 748:	f3 c3                	repz retq 
 74a:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

0000000000000750 <frame_dummy>:
 750:	55                   	push   %rbp
 751:	48 89 e5             	mov    %rsp,%rbp
 754:	5d                   	pop    %rbp
 755:	e9 66 ff ff ff       	jmpq   6c0 <register_tm_clones>
 75a:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

0000000000000760 <__libc_csu_init>:
 760:	41 57                	push   %r15
 762:	41 56                	push   %r14
 764:	49 89 d7             	mov    %rdx,%r15
 767:	41 55                	push   %r13
 769:	41 54                	push   %r12
 76b:	4c 8d 25 3e 06 20 00 	lea    0x20063e(%rip),%r12        # 200db0 <__frame_dummy_init_array_entry>
 772:	55                   	push   %rbp
 773:	48 8d 2d 3e 06 20 00 	lea    0x20063e(%rip),%rbp        # 200db8 <__init_array_end>
 77a:	53                   	push   %rbx
 77b:	41 89 fd             	mov    %edi,%r13d
 77e:	49 89 f6             	mov    %rsi,%r14
 781:	4c 29 e5             	sub    %r12,%rbp
 784:	48 83 ec 08          	sub    $0x8,%rsp
 788:	48 c1 fd 03          	sar    $0x3,%rbp
 78c:	e8 df fd ff ff       	callq  570 <_init>
 791:	48 85 ed             	test   %rbp,%rbp
 794:	74 20                	je     7b6 <__libc_csu_init+0x56>
 796:	31 db                	xor    %ebx,%ebx
 798:	0f 1f 84 00 00 00 00 	nopl   0x0(%rax,%rax,1)
 79f:	00 
 7a0:	4c 89 fa             	mov    %r15,%rdx
 7a3:	4c 89 f6             	mov    %r14,%rsi
 7a6:	44 89 ef             	mov    %r13d,%edi
 7a9:	41 ff 14 dc          	callq  *(%r12,%rbx,8)
 7ad:	48 83 c3 01          	add    $0x1,%rbx
 7b1:	48 39 dd             	cmp    %rbx,%rbp
 7b4:	75 ea                	jne    7a0 <__libc_csu_init+0x40>
 7b6:	48 83 c4 08          	add    $0x8,%rsp
 7ba:	5b                   	pop    %rbx
 7bb:	5d                   	pop    %rbp
 7bc:	41 5c                	pop    %r12
 7be:	41 5d                	pop    %r13
 7c0:	41 5e                	pop    %r14
 7c2:	41 5f                	pop    %r15
 7c4:	c3                   	retq   
 7c5:	90                   	nop
 7c6:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
 7cd:	00 00 00 

00000000000007d0 <__libc_csu_fini>:
 7d0:	f3 c3                	repz retq 

Disassembly of section .fini:

00000000000007d4 <_fini>:
 7d4:	48 83 ec 08          	sub    $0x8,%rsp
 7d8:	48 83 c4 08          	add    $0x8,%rsp
 7dc:	c3                   	retq   
