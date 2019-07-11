#include"header.h"

char keystroke_device[] = "keystroke";

DECLARE_TASKLET(keystroke_tasklet,keystroke_tasklet_handler,)

irq_handler_t keystroke_irq_handler(int irq, void *drvdata)
{
	pr_notice("hardIRQ handler called! pid = %d\n",current->pid);
	pr_notice("In hard IRQ context: %lu \n",in_irq());
	pr_notice("In soft IRQ context: %lu \n",in_softirq());
	pr_notice("In interrupt context: %lu \n",in_interrupt());

	tasklet_schedule(&keystroke_tasklet);
	
	return IRQ_HANDLED;
}

static int __init keystroke_init(void)
{
	int ret = 0;

	pr_notice("Registering keystroke handler for IRQ 1\n");
	
	ret = request_irq(1, keystroke_irq_handler, IRQF_SHARED, keystroke_device, THIS_MODULE);

	if (unlikely(ret)) {
		goto out;
	}
	pr_notice("Keystroke IRQ registered\n");

out: 
	return ret;

}
