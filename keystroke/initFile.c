#include"header.h"

char keystroke_device[] = "keystroke";


irqreturn_t keystroke_handler(int irq, void *d)
{				


}

static int __init keystroke_init(void)
{
	int ret = 0;

	ret = request_irq(1, keystroke_handler, IRQF_SHARED, keystroke_device, THIS_MODULE);

	if (unlikely(ret)) {
		goto out;
	}
	pr_notice("Ketstroke IRQ registered..\n");

out:
	return ret;

}
